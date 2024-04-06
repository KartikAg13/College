//enums are similar to structs in terms of syntax
enum IpAddrKind {
    V4(u8, u8, u8, u8),
    V6(String)
}

enum Message {
    Quit, 
    Move { x: i32, y: i32 },    //struct inside an enum
    Write(String),
    ChangeColor(i32, i32, i32)
}

//implementation block for functions/methods
impl Message {
    fn some_function() {
        println!("Lets get rusty");
    }
}

fn main() { 
    let _localhost:IpAddrKind = IpAddrKind::V4(127, 0, 0, 1);
    Message::some_function();

    value_in_cents(Coin::Quarter(UsState::Alaska));
}

//passing an enum to a function
fn route(_ip_kind: IpAddrKind) {}

#[derive(Debug)]    //this makes it easy to print an enum
enum UsState {
    Alabama, 
    Alaska,
    Arizona,
    Arkansas,
    California
    //...
}

enum Coin {
    Penny, 
    Nickel,
    Dime, 
    Quarter(UsState)
}

fn value_in_cents(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => {
            println!("Lucky penny");
            1
        }
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter(state) => {
            println!("Start quarter from {:?}!", state);
            25
        }
    }
}