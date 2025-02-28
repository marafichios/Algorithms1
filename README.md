# Algorithms1

## HOMEWORK NO 1, PA

### Servere

* For this problem I used a binary search to find the right power. I chose an
error of 0.001 to search in either the higher or the lower part of the
interval, ensuring the result is narrowed down and very precise. The left and
right parts are set to the minimum and maximum value of the vector, so that I
can be able to search the value throughout the hole vector. The highest minimum
is calculated by resetting the left and right values, and the result is
calculated with the help of the formula given in the problem. 
* Spacial complexity: O(N)
* Time complexity: O(N * logN)


### Colorare

* For this problem I first found some formulas by solving it with pen and
paper. I found that for consecutive blocks of H, the number of ways to color
them is 2 * 3^H, where H is the number of H blocks, and for consecutive blocks
of V, the number of ways to color them is 2 * 3^(V - 1). For alternating blocks
I compressed them so that i have only H V H ... or V H V ... sequences. And the
formula for this is calculated by dividing the other formulas by 3^(no. 
of blocks - 1). The code implementation didnt take long afterwards, as I used
a struct for each block/rectangle to keep the number and type. The power
function is taken from the lab solutions, as it is more efficient.
* Spacial complexity: O(N)
* Time complexity: O(N + log m): where log m comes from the power function


### Compresie

* This problem was quickly solved by using 2 vectors to store the partial sums
of each input vector. I found that the number of equal elements in the new
vectors gives off the number of compressions that have to be done. As these two
vectors are already sorted in ascending order, when the elements were not
equal, I incremented the index of the vector that had the smaller element.
For the case where no compression is found, I checked whether the last elements
in the partial sums vectors are equal, because if a compression is possible, the
sums of the initial arrays will always be tha same.
* Spacial complexity: O(n + m)
* Time complexity: O(n + m)


## Criptat - solved the dynamic programming part with ChatGPT

* For this problem I used a matrix to store the frequenies of the letters of
the given words, each line being asssociated with a word, hence the matrix is
n x 26. I then used another matrix to store the maximum frequency of each
letter from a to z, making combinations of words to create a password of length
len, from the maximum possible length down to the length of the current word.
Then I check if this word added to the password results in a greater password,
so I can update the matrix. I then check the condition of the problem, to
see if the frequency of the letter is greater than half of len, and then I get
the highesst value of len, as it is the maximum size of any password that can
be formed.
* I used chatGPT to help me with the dynamic programming part, and it gave me
the right idea to iterate in descending order from a maximum size of password
down to the size of the word, and to get the max for the dp matrix. I asked
for a dynamic programming approach, as I gave it the first part of the problem
and explained the second part and the conditions. 
* Spacial complexity: O(26 * length of all words)
* Time complexity: O(26 * length of all words * n)


## Oferta

* For this problem I only solved the first part, without the bonus and I used
dynamic programming to get the best price possible in an efficient way. The
base case is represented by the sum before and the price of the element before.
I used a big value so I could get the min out of those two. Then there are 2
cases: the one applied when 2 products are addiacent and the price is given 
by the sum of the products chosen before and the offer given in the text (for
2 products), annd the other case applied for 3 products. When they are
addiacent, the prices is, again, given by the sum before and the offer
available for 3 products. Each time I calculate the min price, as the client
wants to get the best deal.
* Spacial complexity: O(N)
* Time complexity: O(N)



    
