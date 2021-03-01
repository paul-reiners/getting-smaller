function [] = display_color_approx(color_channel, color)
%display_color_approx Compress a color jpg image.
%   Displays compressed images of a particular color channel along with
%   compression info.
[u, s, v] = svd(double(color_channel));
for r = [5, 20, 100]
    [compressionRatio, ~] = get_compression_ratio(color_channel, r);
    percent_storage = 100.0 / compressionRatio;
    approx = u(:, 1:r) * s(1:r, 1:r) * v(:, 1:r)';
    figure, imagesc(approx), axis off
    title([color, ', r = ' , num2str(r, '%d'), ', ', num2str(percent_storage,'%.2f') '% storage']);
end
end
