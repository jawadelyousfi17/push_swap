const { exec } = require("child_process");
const readline = require("readline");

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

function calculateAverage(results) {
  const sum = results.reduce((acc, curr) => acc + curr, 0);
  const average = sum / results.length;
  return average;
}

async function main() {
  const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
  });

  const askQuestion = (query) =>
    new Promise((resolve) => rl.question(query, (answer) => resolve(Number(answer))));

  const totalRuns = await askQuestion("Enter the number of iterations: ");
  const numCount = await askQuestion("Enter the number of numbers to generate: ");
  const maxOperations = await askQuestion("Enter the maximum allowed operations: ");
  rl.close();

  const results = [];
  const min = -1000000;
  const max = 1000000;

  for (let i = 0; i < totalRuns; i++) {
    const randomNumbers = generateRandomNumbers(numCount, min, max);

    try {
      const checkerResult = await executeChecker(randomNumbers);
      if (checkerResult !== "OK") {
        console.error(`Run ${i + 1}: Checker result is not OK! (${checkerResult})`);
        console.log("Numbers:", randomNumbers.join(" "));
        return; // Stop the process on first failure
      }

      const operationCount = await executePushSwap(randomNumbers);
      results.push(operationCount);

      if (operationCount > maxOperations) {
        console.error(
          `Run ${i + 1}: Error! Operation count exceeds ${maxOperations} (Count: ${operationCount})`
        );
        console.log("Numbers:", randomNumbers.join(" "));
        console.log("Average Result:", averageResult);
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

  const averageResult = calculateAverage(results);
  console.log("Average Result:", averageResult);
  console.log("All runs completed successfully!");
}

main();
