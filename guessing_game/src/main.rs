use std::io;
use std::cmp::Ordering;
use rand::Rng;
use colored::*;

fn main() {

    //generate a random number
    let secret_number:u32 = rand::thread_rng().gen_range(1, 101);

    println!("Secret Number: {}", secret_number);

    println!("Guess Number:");

    //if the user guesses a wrong number then continue the game
    loop {
        //create a dynamic mutable string
        let mut guess = String::new();

        println!("Please enter a number: ");

        //like python, rust also takes only string as input
        io::stdin()
            .read_line(&mut guess)
            .expect("Failed to read line");

        //use shadowing and convert string to integer
        //if the string is not a number then continue to the next iteration
        let guess:u32 = match guess.trim().parse() {
            Ok(num) => num,
            //if any type of error is encountered then continue to next iteration
            Err(_) => continue
        };

        //comparing two numbers
        match guess.cmp(&secret_number) {

            //use colored library to change the color of the text on the terminal
            //the string is then passed as argument
            Ordering::Less => println!("{}", "Too small".red()),

            //terminate loop when the number is guessed
            Ordering::Equal => {
                println!("{}", "You win".green());
                break;
            },
            Ordering::Greater => println!("{}", "Too big".red())
        }
    }
}
