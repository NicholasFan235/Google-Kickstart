T = 1;
N = [1 100];
S = [1 1];
E = [1 1e5];
L = [1 1e5];

fprintf("\n%d\n", T);
for t = 1:T
    n = randi(N(2)-N(1)+1) + N(1)-1;
    fprintf("%d\n", n);
    for i = 1:n
        s = randi(S(2)-S(1)+1) + S(1)-1;
        e = randi(E(2)-E(1)+1) + E(1)-1;
        l = randi(L(2)-L(1)+1) + L(1)-1;
        fprintf("%d %d %d\n", s, e, l);
    end
end