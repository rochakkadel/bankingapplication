This is a simple banking program that allows users to perform basic banking operations such as signing up, signing in, changing passwords, depositing money, withdrawing money, and validating credit card numbers.

 How to Use

1. Signup: Create a new account by providing a unique username and a 4-digit password.

2. Signin: Log in to your account using your username and password.

3. Change Password: Change your account password after logging in by providing your old password and selecting a new 4-digit password.

4. Deposit: Add money to your account by specifying the amount you want to deposit.

5. Withdraw: Withdraw money from your account by specifying the amount you want to withdraw. Ensure you have sufficient balance before withdrawing.

6. Credit Card Validator: Validate a credit card number by entering it without spaces. The program will check if the card number is valid.

How It Works

Account Creation: When signing up, the program checks if the chosen username is available and creates a new account file with the username and password.

Account Validation: When signing in, the program checks if the entered password matches the password associated with the username.

Password Security: Passwords must be 4 digits long and cannot be easily guessed (e.g., "1234", "0000", "4321").

Banking Operations: After signing in, users can deposit or withdraw money. The program stores the account balance in a file named `[username].balance`.

Credit Card Validation: Users can validate credit card numbers to check if they are valid according to the Luhn algorithm.

Additional Notes

- The program uses file handling to store user account information and balances.
- Error handling is implemented to handle invalid inputs and account actions.
