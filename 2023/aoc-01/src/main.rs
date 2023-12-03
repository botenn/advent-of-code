use std::fs;

fn main() {
    let mut answer = 0;
    let contents = fs::read_to_string("input.txt").expect("Couldnt read input");
    let commands: Vec<&str> = contents.split("\n").collect();
    for command in commands {
        let cali_value = process_command(&command);
        answer += cali_value;
    }

    println!("P1 Answer: {}", answer);
}

fn process_command(command: &str) -> u32 {
    let digits: Vec<u32> = command.chars().filter_map(|c| c.to_digit(10)).collect();

    if let (Some(&first), Some(&last)) = (digits.first(), digits.last()) {
        first * 10 + last
    } else {
        0
    }
}
