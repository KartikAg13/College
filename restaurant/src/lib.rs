mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}
    }
}

pub fn eat_at_restaurant() {
    //by default the child module is always private
    //absolute path
    crate::front_of_house::hosting::add_to_waitlist();

    //relative path
    front_of_house::hosting::add_to_waitlist();

    //by default everything is private
    //since seasonal_fruit is private, we cannot create Breakfast struct inside this function
    let mut meal:Breakfast = back_of_house::Breakfast::summer("Rye");

    meal.toast = String::from("Wheat");

    //attributes/variables inside an enum are public
    let order1:Appetizer = back_of_house::Appetizer::Soup;
    let order2:Appetizer = back_of_house::Appetizer::Salad;
}

fn serve_order() {}

mod back_of_house {
    fn fix_incorrect_order() {
        cook_order();
        //super gives access to the crate
        super::serve_order();

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
    }

    fn cook_order() {}
}