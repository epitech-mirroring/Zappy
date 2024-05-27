use std::io::Write;

pub fn hello_world<W: Write>(writer: &mut W) {
    write!(writer, "Hello, world!").unwrap();
}

fn main() {
    hello_world(&mut std::io::stdout());
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_hello_world() {
        let mut buffer = Vec::new();
        hello_world(&mut buffer);
        assert_eq!(buffer, b"Hello, world!");
    }
}
