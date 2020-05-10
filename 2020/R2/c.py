import itertools

TPC = "TPC"

def dfs(t, dep):
    if dep > 2: return dep
    if t.find(TPC) != -1: return dep
    n = len(t)
    res = 3
    for i in xrange(0, n):
        for j in xrange(i + 1, n):
            s = t[:i] + t[i:j+1][::-1] + t[j+1:]
            ret = dfs(s, dep + 1)
            if ret < res: res = ret
    return res

def init():
    s = "TPC**"
    perm = itertools.permutations(s, len(s))
    lst = [ ''.join(p).strip("*").replace("**", "*") for p in perm]
    table = { k: dfs(k, 0) for k in lst }
    return table

def match(s, k):
    p = 0
    for t in k.split("*"):
        p = s.find(t, p)
        if p == -1: return False
        p = p + len(t)
    return True

def main():
    table = init()
    T = input()
    while T > 0:
        T = T - 1
        n = int(raw_input())
        s = raw_input()
        sovlable = all(map(lambda x: x in s, TPC))
        if not sovlable:
            print "Impossible"
            continue

        ans = 3
        for k, v in table.iteritems():
            if ans > v and match(s, k):
                ans = v
        print ans 

if __name__ == "__main__":
    main()
