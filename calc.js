const add = (x, y) => {return x + y;};
const subtract = (x, y) => {return x - y;};
const divide = (x,y) => {
    if (y === 0) {throw new Error("Cannot divide by 0");} 
    else {return x/y;};
    }
const multiply = (x,y) => {return x * y;};
const modulus = (x,y) => {return x % y;};

function operate(operator, x, y){
    switch (operator){
        case "+": 
            return add(x,y);
        case "-":
            return subtract(x,y);
        case "/":
            return divide(x,y);
        case "*":
            return multiply(x,y);
        case "%":
            return modulus(x,y);
        default:
            return y; // If no operator, just return the second number
    }
}

// Calculator state variables
let firstNumber = null;
let currentOperator = null;
let waitingForSecondNumber = false;

function displayNumber(number){
    const display = document.getElementById("display");
    // If we're waiting for a second number (after operator clicked), replace display
    if (waitingForSecondNumber) {
        display.textContent = number;
        waitingForSecondNumber = false;
    } else if (display.textContent === "0") {
        display.textContent = number;
    } else {
        display.textContent += number;
    }
}

function displayOperator(operator){
    const display = document.getElementById("display");
    const inputValue = parseFloat(display.textContent);
    
    // If there's already a first number and operator, calculate first
    if (firstNumber !== null && currentOperator !== null && !waitingForSecondNumber) {
        const result = operate(currentOperator, firstNumber, inputValue);
        display.textContent = result;
        firstNumber = result;
    } else {
        firstNumber = inputValue;
    }
    
    currentOperator = operator;
    waitingForSecondNumber = true;
}

function displayEquals(){
    const display = document.getElementById("display");
    
    if (firstNumber !== null && currentOperator !== null) {
        const secondNumber = parseFloat(display.textContent);
        try {
            const result = operate(currentOperator, firstNumber, secondNumber);
            display.textContent = result;
            // Reset state after calculation
            firstNumber = null;
            currentOperator = null;
            waitingForSecondNumber = false;
        } catch (error) {
            display.textContent = "Error";
            firstNumber = null;
            currentOperator = null;
            waitingForSecondNumber = false;
        }
    }
}

// Add event listeners to all number buttons
const numberButtons = document.querySelectorAll(".btn.number");
numberButtons.forEach(button => {
    button.addEventListener("click", () => {
        displayNumber(button.textContent);
    });
});

const operatorButtons = document.querySelectorAll(".btn.operator");
operatorButtons.forEach(button => {
    button.addEventListener("click", () => {
        displayOperator(button.textContent);
    });
});

const equalsButton = document.querySelector(".btn.equals");
equalsButton.addEventListener("click", () => {
    displayEquals();
});

// Clear button functionality
const clearButtons = document.querySelectorAll(".btn.clear");
clearButtons.forEach(button => {
    button.addEventListener("click", () => {
        const display = document.getElementById("display");
        if (button.textContent === "C") {
            // Clear everything
            display.textContent = "0";
            firstNumber = null;
            currentOperator = null;
            waitingForSecondNumber = false;
        } else if (button.textContent === "CE") {
            // Clear entry - just reset display
            display.textContent = "0";
        }
    });
});