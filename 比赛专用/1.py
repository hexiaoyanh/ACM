while True:
    try:
        n=input()
        h=[]
        for i in range(0,n):
            h+=raw_input()
        print (h)
    except EOFError:
        break;
