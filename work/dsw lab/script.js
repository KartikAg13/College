function check() {
    var first = parseInt(document.getElementById('first').value);
    var second = parseInt(document.getElementById('second').value)
    var diff1 = Math.abs(100 - first);
    var diff2 = Math.abs(100 - second);
    var less = first;
    if(diff1 > diff2) {
        less = second;
    }
    document.getElementById('result').innerHTML = less;
}