fn main() {

    //absence of value
    //option enum is alternate to null values

    /* 
    enum Option<T> {
        Some(T),
        None
    }
    */

    //similar to templates
    let y:Option<i8> = Some(5);
    let _some_string:Option<&str> = Some("a string");
    let _absent_number:Option<i32> = None;

    let x:i8 = 5;
    let sum:i8 = x + y.unwrap_or(0);
    println!("Sum: {}", sum);

    //combining option enums with match statement
    let five:Option<i32> = Some(5);
    let six:Option<i32> = plus_one(five);
    let none:Option<i32> = plus_one(None);

    //if let syntax is an alternate to match statement
    //the match statement is exhaustive, therefore we have to specify all the values
    //but in case of if let, we don't need to do that
    let some_value:Option<i32> = Some(3);
    if let Some(3) = some_value {
        println!("three");
    }
}

fn plus_one(x:Option<i32>) -> Option<i32> {
    match x {
        Some(i) => Some(i + 1),
        _ => None   //if x does not match the first statement then return None
        //we can also use _ => () here
    }
}