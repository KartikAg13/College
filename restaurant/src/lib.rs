//nested paths
use rand::{Rng, CryptoRng, ErrorKind::Transient};

//example - use std::io::{self, Write};

mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}
    }
}

//absolute path
//use as to rename
//this brings the hosting module in scope
//using pub makes the hosting module available to exporting
pub use crate::front_of_house::hosting as host;
use crate::back_of_house::{Breakfast, Appetizer};

//realtive path - use self::front_of_house::hosting;

pub fn eat_at_restaurant() {
    let secret_number:i32 = rand::thread_rng().gen_range(1, 101);

    //by default the child module is always private
    //no need to write crate::front_of_house since we have specified use above
    host::add_to_waitlist();

    //by default everything is private
    //since seasonal_fruit is private, we cannot create Breakfast struct inside this function
    let mut meal:Breakfast = back_of_house::Breakfast::summer("Rye");
    meal.toast = String::from("Wheat");

    //attributes/variables inside an enum are public
    let _order1:Appetizer = back_of_house::Appetizer::Soup;
    let _order2:Appetizer = back_of_house::Appetizer::Salad;
}

fn serve_order() {}

mod back_of_house {
    pub fn fix_incorrect_order() {
        cook_order();
        //super gives access to the crate
        super::serve_order();
    }

    pub struct Breakfast {
        pub toast: String,
        seasonal_fruit: String
    }

    impl Breakfast {
        pub fn summer(toast: &str) -> Breakfast {
            Breakfast {
                toast: String::from(toast),
                seasonal_fruit: String::from("peaches")
            }
        }
    }

    pub enum Appetizer {
        Soup, 
        Salad
    }

    fn cook_order() {}
}