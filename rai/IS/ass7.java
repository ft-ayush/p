import java.security.MessageDigest;
import java.util.Scanner;

class ass7 {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the text: ");
        String input = scanner.nextLine();

        MessageDigest md = MessageDigest.getInstance("MD5");
        md.update(input.getBytes());
        byte[] digest = md.digest();

        StringBuilder hexString = new StringBuilder();
        for (byte b : digest) {
            hexString.append(String.format("%02x", b & 0xff));
        }

        System.out.println("MD5 Hash: " + hexString.toString());
    }
}
