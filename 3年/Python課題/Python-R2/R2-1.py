def isPrime(n):
    flag = True
    for i in range(2,n):
        if n % i == 0:
            flag = False
            break
        else:
            flag = True      
            
    if n == 1:
        flag = False
                
    return flag

def isList():
    i = 2
    j = 1
    x = []
    while 1:
        if isPrime(i):
            x.append(i)
            j += 1
        i += 1
        if j == 100:
            break
    return x

def isSearch(n):
    n = n - 1 
    x = isList()
    return x[n]
            
            
def main():
    x = input("正の整数を入力してください： ")
    x = int(x)
    print(x, "=", isPrime(x))
    print("1～100までの素数のリストを表示します。")
    print(isList())
    
    n = input("整数n(1～100)を入力してください：")
    n = int(n)
    print(n, "番目の素数は", isSearch(n), "です。")


if __name__ == "__main__":
    main()