#include <stdbool.h>
#include <stdio.h>

bool isPalindrome(int num) {
	int reversedNum = 0;
	int originalNum = num;

	while (num > 0) {
		int digit = num % 10;
		reversedNum = reversedNum * 10 + digit;
		num /= 10;
	}

	return originalNum == reversedNum;
}

int main() {
	int largestPalindrome = 0;

	for (int i = 100; i <= 999; i++) {
		for (int j = 100; j <= 999; j++) {
			int product = i * j;
			if (isPalindrome(product) && product > largestPalindrome) {
				largestPalindrome = product;
			}
		}
	}

	FILE* file = fopen("102-result", "w"); // Open the file in write mode
	fprintf(file, "%d", largestPalindrome); // Write the largest palindrome to the file without any extra space or new line
	fclose(file); // Close the file

	return 0;
}
