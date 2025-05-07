// Importing necessary classes from the Java Standard Library
import java.security.MessageDigest;  // Provides the MessageDigest class to compute hash functions (like MD5)
import java.security.NoSuchAlgorithmException;  // Exception handling if the algorithm (e.g., MD5) is not available
import java.util.Scanner;  // To get user input from the console

/**
 * This is a public class named MD5DigestExample.
 * A class in Java is a blueprint for creating objects and grouping data (fields) and behavior (methods) together.
 * Public means it can be accessed from any other class in any package.
 */
public class MD5DigestExample {

    /**
     * The main method is the entry point of any Java application.
     * 'public' allows it to be called from outside the class.
     * 'static' means it belongs to the class, not to any instance of the class.
     * 'void' means it doesn't return any value.
     * 'String[] args' is used to take command-line arguments (if any).
     */
    public static void main(String[] args) {

        // Creating a Scanner object to take user input from the console
        Scanner scanner = new Scanner(System.in);

        // Prompting the user to enter the text
        System.out.print("Enter the text to hash with MD5: ");
        String inputText = scanner.nextLine();  // Reading the entire line of input

        // Calling the getMD5Digest method to compute the MD5 hash of the input text
        String md5Hash = getMD5Digest(inputText);

        // Displaying the result
        System.out.println("MD5 Digest: " + md5Hash);

        // Closing the scanner to free system resources
        scanner.close();
    }

    /**
     * This is a static method that takes a String input and returns its MD5 hash as a hexadecimal string.
     * A method in Java defines behavior. It is similar to a function in other programming languages.
     * We use 'static' because we don't need to create an object of the class to call this method.
     * The method may throw a NoSuchAlgorithmException if MD5 is not supported on the platform.
     */
    public static String getMD5Digest(String input) {
        try {
            // MessageDigest is a class provided by java.security for hashing operations.
            // 'getInstance("MD5")' initializes it to use the MD5 hashing algorithm.
            MessageDigest md = MessageDigest.getInstance("MD5");

            // The update method processes the input string (converted to bytes).
            // getBytes() converts the string into a byte array using platform's default charset.
            md.update(input.getBytes());

            // digest() completes the hash computation and returns the resulting byte array.
            byte[] digestBytes = md.digest();

            // A StringBuilder is used to build the hexadecimal representation of the byte array efficiently.
            StringBuilder hexString = new StringBuilder();

            // Loop through each byte in the digest
            for (byte b : digestBytes) {
                // Format the byte into a two-digit hexadecimal value and append to the string
                hexString.append(String.format("%02x", b & 0xff));
            }

            // Return the final hexadecimal string
            return hexString.toString();

        } catch (NoSuchAlgorithmException e) {
            // This exception is thrown if the algorithm (MD5) is not available in the environment
            System.err.println("MD5 Algorithm not found: " + e.getMessage());
            return null;
        }
    }
}


/*
$ javac MD5DigestExample.java   # Compiling the Java program
$ java MD5DigestExample         # Running the compiled program
Enter the text to hash with MD5: hello world
MD5 Digest: 5eb63bbbe01eeed093cb22bb8f5acdc3
*/