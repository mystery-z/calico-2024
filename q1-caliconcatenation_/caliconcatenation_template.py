def solve(S: str) -> str:
	global x
	if S[0] == "o":
		S = S.replace("o","CALICO", 1)
	elif S[:2] == "co":
		S = S.replace("co","CALICO", 1)
	elif S[:3] == "ico":
		S = S.replace("ico", "CALICO", 1)
	elif S[:4] == "lico":
		S = S.replace("lico", "CALICO", 1)
	elif S[:5] == "alico":
		S = S.replace("alico", "CALICO", 1)
	elif S[:6] == "calico":
		x_start = S[:6].upper()
		Y = len(S)-1
		x_end = S[7:Y]
		S = x_start+x_end
	return S


def main():
    T = int(input())
    for _ in range(T):
        S = input()
        print(solve(S))


if __name__ == '__main__':
    main()
