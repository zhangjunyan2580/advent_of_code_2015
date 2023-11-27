import json
import regex

js_file = open("day12.txt")
obj = json.load(js_file)
js_file.close()

def traverse(obj) -> bool:
    if isinstance(obj, dict):
        rm_list = []
        for k, v in obj.items():
            if v == "red":
                return True
            if isinstance(v, (dict, list)):
                if traverse(v):
                    rm_list.append(k)
        for k in rm_list:
            obj.pop(k)
    elif isinstance(obj, list):
        rm_list = []
        for i in range(len(obj)):
            if obj[i] == "red":
                rm_list.append(i)
            if isinstance(obj[i], (dict, list)):
                if traverse(obj[i]):
                    rm_list.append(i)
        rm_list.reverse()
        for i in rm_list:
            obj.pop(i)
    return False

traverse(obj)
print(obj)