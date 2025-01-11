def calculator():
    num1 = float(input("Enter first number: "))
    operation = input("Enter an operator (+, -, *, /): ")
    num2 = float(input("Enter second number: "))

    if operation == "+":
        print("Result:", num1 + num2)
    elif operation == "-":
        print("Result:", num1 - num2)
    elif operation == "*":
        print("Result:", num1 * num2)
    elif operation == "/":
        if num2 != 0:
            print("Result:", num1 / num2)
        else:
            print("Error! Division by zero.")
    else:
        print("Invalid operator!")

calculator()
