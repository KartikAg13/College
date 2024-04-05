struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool
}
//Debug is a trait
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32
}

//impl holds the methods related to a structure
//we can create multiple impl blocks
//implementation block for methods
impl Rectangle {
    //the first argument should be &self or &mut self in case of methods
    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.height > other.height && self.width > other.width
    }
}

//implementation block for associated functions
impl Rectangle {
    //associated functions don't take &self as argument
    fn square(size: u32) -> Rectangle {
        Rectangle {
            width: size,
            height: size
        }
    }
}

fn main() {
    let mut user1:User = User {
        email: String::from("kartikag234@gmail.com"),
        username: String::from("kartikag234"),
        active: true,
        sign_in_count: 1
    };

    let _name:String = user1.username;
    user1.username = String::from("agkartik234");

    let user2:User = build_user("agkartik234@gmail.com".to_string(), user1.username);

    let _user3:User = User {
        email: String::from("harshit@gmail.com"),
        username: String::from("harshit"),
        ..user2
    };

    //tuple structs
    struct Color(i32, i32, i32);
    struct Point(i32, i32, i32);

    let rect1:Rectangle = Rectangle {
        height: 50,
        width: 30
    };

    let rect2:Rectangle = Rectangle {
        height: 49,
        width: 29
    };

    //syntax to call associated functions
    let _rect3:Rectangle = Rectangle::square(25);

    //use {:?} or {:#?} and #[derive(Debug)]
    println!("Rectangle: {:#?}", rect1);
    println!("The area of the rectangle is: {}", rect1.area());
    println!("rect2 can hold rect1: {}", rect2.can_hold(&rect1));
}

fn build_user(email: String, username: String) -> User {
    User {
        //field init shorthand syntax
        email,
        username,
        active: true,
        sign_in_count: 1
    }
}