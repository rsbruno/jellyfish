class Tag:
    def ExtractTags(file):
        listTags = []
        for n, line in enumerate(file):
            for i, x in enumerate(line):
                if x == "<":
                    j = i
                    while j < len(line) and (line[j] != " " and line[j] != ">"):
                        j += 1
                    listTags.append(
                        {"name": line[i+1:j],
                         "pos": {"l": n, "s": i+1, "e": j}},
                    )
        return listTags
