const { exec } = require("child_process");

function generateRandomNumbers(count, min, max) {
    const numbersSet = new Set();
    while (numbersSet.size < count) {
      const randomNum = Math.floor(Math.random() * (max - min + 1)) + min;
      numbersSet.add(randomNum);
    }
    return Array.from(numbersSet);
  }

function executeChecker(numbers) {
  return new Promise((resolve, reject) => {
    const numbersString = numbers.join(" ");
    exec(`arg="${numbersString}" && ./push_swap $arg | ./checker_Mac $arg`, (error, stdout, stderr) => {
      if (error) {
        reject(`Execution error: ${stderr || error.message}`);
        return;
      }
      resolve(stdout.trim());
    });
  });
}

function executePushSwap(numbers) {
  return new Promise((resolve, reject) => {
    const numbersString = numbers.join(" ");
    exec(`arg="${numbersString}" && ./push_swap $arg | wc -l`, (error, stdout, stderr) => {
      if (error) {
        reject(`Execution error: ${stderr || error.message}`);
        return;
      }
      resolve(parseInt(stdout.trim(), 10));
    });
  });
}

async function main() {
    const results = []
  const totalRuns = 500;
  const maxOperations = 12;

  for (let i = 0; i < totalRuns; i++) {
    const randomNumbers = generateRandomNumbers(5, -1000000, 1000000);

    try {
      const checkerResult = await executeChecker(randomNumbers);
      if (checkerResult !== "OK") {
        console.error(`Run ${i + 1}: Checker result is not OK! (${checkerResult})`);
        console.log("Numbers:", randomNumbers.join(" "));
        return; // Stop the process on first failure
      }

      const operationCount = await executePushSwap(randomNumbers);
      results.push(operationCount);
      if (operationCount > 10) console.log("Not good !", ` ${operationCount}`);
      if (operationCount > maxOperations) {
        console.error(`Run ${i + 1}: Error! Operation count exceeds ${maxOperations}`);
        console.log("Numbers:", randomNumbers.join(" "));
        return; // Stop the process on first error
      }
    } catch (error) {
      console.error(`Run ${i + 1}: An error occurred:`, error);
      return; // Stop the process on first error
    }

    if ((i + 1) % 100 === 0) {
      console.log(`Completed ${i + 1} runs...`);
    }
  }
//   console.log(results);
function calculateAverage(results) {
    const sum = results.reduce((acc, curr) => acc + curr, 0);
    const average = sum / results.length;
    return average;
}

const averageResult = calculateAverage(results);
console.log("Average Result:", averageResult);
  console.log("All runs completed successfully!");
}

main();
