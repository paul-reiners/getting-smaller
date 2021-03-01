A = imread('../../../img/big_sur.jpeg');
[n, m] = size(A);
beta = m / n;
sigma_known = 0;
coef = optimal_SVHT_coef(beta, sigma_known);
disp(coef);
