def rpn(tokens, data_list):
    stack = []

    for token in tokens:
        if token == '+':
            y = stack.pop()
            x = stack.pop()
            stack.append(x + y)
        elif token == '-':
            y = stack.pop()
            x = stack.pop()
            stack.append(x - y)
        elif token == '*':
            y = stack.pop()
            x = stack.pop()
            stack.append(x * y)
        elif token == '/':
            y = stack.pop()
            x = stack.pop()
            stack.append(x / y)
        else:
            for data in data_list[0]:
                if token in data:
                    index = data_list[0].index(data)
                    stack.append(float(data_list[1][index]))
                    break

    return stack.pop()

def main():
    equation = input("式を入力してください: ")
    tokens = equation.split()
    data_list = [[], []]
    for token in tokens:
        if token != '+' and token != '-' and token != '*' and token != '/':
            print("変数に対応する値を入力してください. [" + token + "]: ", end = "")
            value = input()
            data_list[0].append(token)
            data_list[1].append(value)

    result = rpn(tokens, data_list)
    print(f"計算結果: ", result)

if __name__ == "__main__":
    main()
