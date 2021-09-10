from classes.Tag import Tag

file = open("example.html")

Tags = Tag.ExtractTags(file)

for tag in Tags:
    print("linha -> "+ str(tag["pos"]["l"])+" "+tag["name"])