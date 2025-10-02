void decode_steganography(int image_data[], int data_size, std::string key) {
    int currentIndex = 1000;

    // TODO: Implement the solve_steganography function.
    /**
     * Implement a loop to decrypt the message, starting from index 1000.
     *
     * Every character is just a number (its ASCII code).
     * Type casting allows you to switch between these two views.
     *
     * - To get a number from a character: (int)key_char
     *   Example: (int)'A' results in the integer 65.
     * - To get a character from a number: (char)secret_value
     *   Example: (char)65 results in the character 'A'.
     *
     * The decryption process is as follows:
     * - Use the ASCII value of the repeating `key` characters to determine the jump distance.
     *   (Hint: use the modulo '%' operator).
     * - Update your current index with the jump distance, then read the value from `image_data`.
     *   Remember to always stay within the array bounds!
     * - If the value is 0, stop the loop. Otherwise, cast the value to a `char` and print it.
     */

    if (data_size <= 0 || key.empty()) return;

    // normalize starting index
    currentIndex %= data_size;
    if (currentIndex < 0) currentIndex += data_size;

    int keyIndex = 0;  // (중복 선언 제거)
    const int K = static_cast<int>(key.size());

    while (true) {
        // 1) read first
        int val = image_data[currentIndex];
        if (val == 0) break;
        std::cout << static_cast<char>(val);

        // 2) then jump (wrap with modulo, use unsigned char for safety)
        unsigned jump = static_cast<unsigned>(static_cast<unsigned char>(key[keyIndex]));
        currentIndex = (currentIndex + static_cast<int>(jump)) % data_size;
        if (currentIndex < 0) currentIndex += data_size;

        keyIndex = (keyIndex + 1) % K;
    }
}
