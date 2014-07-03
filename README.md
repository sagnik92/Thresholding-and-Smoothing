Thresholding-and-Smoothing
==========================

It takes a grey-scale image as input,coverts it into a two-toned binary matrix and smoothens the image i.e rectifies noise bits

 How it works:- This code has two major fuctions-
                a. THRESHOLDING
                B. SMOOTHING
   
    
    THRESHOLDING :-
 
 1) It takes a grayscale image as input, which is a matrix that can contain any values between 0 and 255.
 
 2) Scanning the entire matrix only once, it counts the frequency of occurence each value in the matrix and stores them      separately in 
    an array.
  
 3) It finds out two values whose frequency are the highest- one in the rance 0 to 127 and another in the range 128 to 255.
    
 4) It then calculates the mean of the two values.
 
 5) By comparing with the mean, each value of the matrix is converted to eather 0 or 1. If value <= mean, '1' replaces the      value. Otherwise '0' replaces it.
     
    Thus in this way, the entire matrix is converted to a teo-tone binary matrix.
    
    
    SMOOTHING :-
    
 1) The code now takes the two-tone, binary matrix as input.
 
 2) For the purpose of smoothing, the code creates a n auxillary matrix by 'bordering operation' on the two-tone matrix.        This is done by cloning the binary values of the border cells to all the adjacent cells that are outside the boundary of     the matrix.
    
 3) The code then scans all the eight neighborhood cells of the input binary matrix.
    If 5 or more neighbourhood cells contain the same binary value as the traversed cell,then the cell retains it's value.
    Otherwise,the binary value is inverted i.e 0 changed to 1 or vice versa by XOR operation on it.
    
