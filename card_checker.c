#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long card_num = get_long("Card Number:");

    // 1st Check: The smallest is a Visa starting with 4 and with 13 digits. The biggest is MasterCard, 55, 16 digits.
    if (card_num >= 4000000000000 && card_num < 5600000000000000)
    {
        int total = 0;
        long num = card_num;

        while (num > 9)
        {
            // Multiply every other digit by 2, starting with the number’s second-to-last digit
            int mult = ((num % 100) / 10) * 2;

            // add those products’ digits together.
            int sum = mult / 10 + mult % 10;

            // Add the sum to the sum of the digits that weren’t multiplied by 2
            total += sum + num % 10;

            num = num / 100;
        }
        total += num;

        // 2nd Check: total's last number must be 0
        if (total % 10 == 0)
        {
            int am_ex = card_num / 10000000000000;

            // MasterCard numbers start with 51, 52, 53, 54, or 55 and uses 16-digit numbers
            if (card_num > 5099999999999999 && card_num < 5600000000000000)
            {
                printf("MASTERCARD\n");
            }

            // American Express numbers start with 34 or 37 and uses 15-digit numbers,
            else if (am_ex == 34 || am_ex == 37)
            {
                printf("AMEX\n");
            }

            // Visa numbers start with 4 and uses 13- and 16-digit numbers
            else if (card_num / 1000000000000 == 4 || card_num / 1000000000000000 == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
