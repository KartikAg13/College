fn main() {

    //by default variables are immutable
    let mut x:i32 = 5;
    println!("The value of x is: {}", x);

    //shadowing
    let x:&str = "six";
    println!("The value of x is: {}", x);

    //constants
    const HIGHEST_PLACEMENT:u32 = 10_000_000;

    //byte (u8 only)
    let e:u8 = b'A';
    println!("The value of e is: {}", e);

    //indexing starts from zero
    let tuple:(&str, i32) = ("kartik", 15);
    //destructuring
    let (name, marks) = tuple;
    //dot notation
    let marks = tuple.1;

    //arrays
    let error_codes = [200, 404, 500];

    //alternate way to declare arrays
    let value:i32 = 1;
    const SIZE:usize = 5;
    let array = [value; SIZE];

    //function call
    let sum:i32 = my_function(11, 22);
    println!("The sum is: {}", sum);

    //control flow
    let mut number:i32 = 5;
    if number > 10 {
        println!("First condition was true");
    }
    else if number < 22 {
        println!("Second condition was true");
    }
    else {
        println!("Third condition was true");
    }

    //something really weird and different using if
    let condition:bool = true;
    number = if condition { 5 } else { 6 };

    //loops
    let mut counter:i32 = 0;
    let result:i32 = loop {
        counter += 1;
        if counter == 10 {
            break counter;
        }
    };
    println!("The result is {}", result);

    //while loop
    while number != 0 {
        println!("{}!", number);
        number -= 1;
    }
    println!("LIFTOFF!!!");

    //for-each loop
    for code in error_codes.iter() {
        println!("The error code is: {}", code);
    }

    //for loop
    for x in 1..4 {
        println!("{}!", x);
    }
}
fn my_function(x:i32, y:i32) -> i32 {
    println!("The value of x is: {}", x);
    println!("The value of y is: {}", y);
    x + y   //return (x + y);
}