fn main() {

    /*
        Ownership rules
    1. Each value in rust has a variable that is called its owner
    2. There can only be one owner at a time
    3. When the owner goes out of scope, the value will be dropped
    */

    let x:i32 = 5;
    let y:i32 = x;  //value in x gets copied

    makes_copy(y);  //makes a copy and value is still present in y
    println!("Integer in main: {}", y);

    let s1:String = String::from("hello");
    let s2:String = s1.clone();    //value in s1 gets copied
    println!("{}, world", s1);

    let mut s3:String = s1; //value in s1 moves to s3
    //println!("{}, world", s1);    Error: value borrowed here after move

    takes_ownership(s2);    //value in s2 moves to some_string and its scope is now restricted to takes_ownership()
    //println!("{}, world", s2);    Error: value borrowed here after move

    s3 = takes_and_gives_back(s3);
    println!("String in main: {}", s3);

    let length:usize = calculate_length(&s3);   //the value in s3 is not moved, its borrowed
    println!("The length of '{}' is {}.", s3, length);

    change(&mut s3);

    /*
        References rules
    1. Scope of reference ends when it is last used
    2. We cannot have two mutable references to the same variable within the same scope
    3. We cannot have a mutable and an immutable reference to the same variable within the same scope
    4. We can have more than one immutable references to the same variable as they don't modify the value
    5. References must be valid
    */

    let r1:&String = &s3;
    //let r2:&mut String = &mut s;  Error: mutable borrow occurs here
    println!("Immutable r1: {}", r1);  //scope of r1 ends here

    let _r4:&String = &s3;   //scope of r4 starts and ends here
    let r3:&mut String = &mut s3;
    println!("Mutable r2: {}", r3);

    //string slices are of the type &str and strings are of the type String
    let s:String = String::from("hello world");
    let word:&str = first_word(&s);
    println!("String slice: {}", word);

    //array slices
    let a = [1, 2, 3, 4, 5];
    let _slice:&[i32] = &a[1..4];
}

fn makes_copy(some_integer:i32) {
    println!("Integer: {}", some_integer);
}

fn takes_ownership(some_string:String) {
    println!("String: {}", some_string);
}

fn takes_and_gives_back(a_string:String) -> String {
    a_string
}

//takes reference to a string as an argument and is known as borrowing
fn calculate_length(s:&String) -> usize {
    //s.push_str("oops");   Error: `s` is a `&` reference, so the data it refers to cannot be borrowed as mutable
    let length:usize = s.len();
    length
}

fn change(some_string:&mut String) {
    some_string.push_str(", world");
}

fn first_word(s:&str) -> &str {
    let bytes:&[u8] = s.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if item == b' ' {
            return &s[..i]; //[0..i]
        }
    }
    &s[..]
}