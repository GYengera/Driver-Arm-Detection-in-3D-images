function recognize(networkx, networky)
load 2Darray.dat;   
x = zeros(3,76800); %%Using raw data as feature to classify each pixel of the image
for i = 1:240
    for j = 1:320
        x(:,320*(i-1) + j) = [j ;i ;X2Darray(i,j)];
    end
end
prediction = sim(networkx,x);   %% networkx is used to classify pixels of the right hand
X = zeros(240,320);
for i = 1:240
    for j = 1:320
        if prediction(320*(i-1) + j)>0.9 && X2Darray(i,j) > 0   %% Threshold of 0.9 is used
            X(i,j) = 1800;
        else 
            X(i,j) = X2Darray(i,j);
        end
    end
end
prediction = sim(networky,x);  %%networky us used to classify pixels of the left hand
for i = 1:240
    for j = 1:320
        if prediction(320*(i-1) + j)>0.9 && X2Darray(i,j) > 0
            X(i,j) = 0;
        else 
            X(i,j) = X(i,j) + 300;
        end
    end
end
imagesc(X);
end