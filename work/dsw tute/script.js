function palindrome() {
    var number = parseInt(document.getElementById('palindrome').value);
    var copy = number;
    var sum = 0;
    while (copy != 0) {
        var remainder = copy % 10;
        sum = sum * 10 + remainder;
        copy = Math.floor(copy / 10);
    }
    if (sum === number) {
        document.getElementById('result').innerHTML = "The number is palindrome";
    }
    else {
        document.getElementById('result').innerHTML = "The number is not palindrome";
    }
}