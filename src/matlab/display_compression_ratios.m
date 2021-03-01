A = imread('../../img/big_sur.jpeg');
color_channel = A(:, :, 1);
for r = [5, 20, 100]
    [compressionRatio, truncatedS] = get_compression_ratio(color_channel, r);
    disp(strcat('r: ', string(r)));
    disp(strcat('compressionRatio: ', string(compressionRatio)));
    disp('truncatedS: ');
    size(truncatedS)
    for ii = 1:r
        disp(truncatedS(ii))
    end
end
