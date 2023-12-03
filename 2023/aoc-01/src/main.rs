use std::fs;

fn main() {
    let contents = fs::read_to_string("input.txt").expect("Couldnt read input");
    let commands: Vec<&str> = contents.split("\n").collect();
    for command in commands {
        let mut cali_values: String;
        for char in command.chars() {
            if char.is_digit() {
                cali_values.push(char);
                reversed: String = command.rev();
                for char in reversed.chars() {
                    if char.is_digit(0..9) {
                        cali_values.push(char);
                    }
                }
            }
        }
        println!("{cali_values}");
    }
}
