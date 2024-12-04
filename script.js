document.getElementById('signupForm').addEventListener('submit', function (e) {
    const password = document.getElementById('signupPassword').value;
    if (password.length < 6) {
        e.preventDefault();
        alert('Password must be at least 6 characters long.');
    }
});

document.getElementById('loginForm').addEventListener('submit', function (e) {
    const email = document.getElementById('loginEmail').value;
    if (!email.includes('@')) {
        e.preventDefault();
        alert('Please enter a valid email address.');
    }
});
