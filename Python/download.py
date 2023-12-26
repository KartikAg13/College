import requests

download = requests.get('https://automatetheboringstuff.com/files/rj.txt')
print(f'Status Code: {download.status_code}')
print(f'Length: {len(download.text)}')
download.raise_for_status()

file = open('RomeoAndJuliet.txt', 'wb')
for chunk in download.iter_content(10000):
    file.write(chunk)
file.close()