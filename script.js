let input = document.getElementById('result');

function appendToInput(value) {
    input.value += value;
}

function clearInput() {
    input.value = '';
}

function calculateResult() {
    try {
        input.value = eval(input.value);
    } catch (error) {
        input.value = 'Error';
    }
}
