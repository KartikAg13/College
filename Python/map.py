import webbrowser, sys, pyperclip

address = ''
if len(sys.argv) > 1:
    address = '+'.join(sys.argv[1:])
else:
    ad = pyperclip.paste().strip()
    for ch in ad:
        if ch == ' ':
            ch = '+'
        address = address + ch

url = 'google.com/maps/place/' + address + '/'
webbrowser.open(url)