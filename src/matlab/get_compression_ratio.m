function [compressionRatio, truncatedS] = get_compression_ratio(color_channel, r)
%UNTITLED Explain how well the color images are compressed, using examples
%and calculating the percent compression.
%   Explain how well the color images are compressed, using examples and
%   calculating the percent compression.
[mBefore, nBefore] = size(color_channel);
[~, s, ~] = svd(double(color_channel), 'econ');
sizeAfter = r * (mBefore + 1 + nBefore);

compressionRatio = double(mBefore * nBefore) / double(sizeAfter);
d = diag(s);
truncatedS = d(1:r);
