A = imread('../../img/big_sur.jpeg');
red = A(:, :, 1);
display_color_approx(red, 'red')
green = A(:, :, 2);
display_color_approx(green, 'green')
blue = A(:, :, 3);
display_color_approx(blue, 'blue')
