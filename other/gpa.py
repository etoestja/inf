# all credits by semester
credits = [[5,7,3,5,6], [4,3,4,3,4,4]]

# all notes by semester
notes   = [[6,6,5,5.5,5], [5.5,5.75,5.75,5.5,5.5,6]]

# GPA = (credits, notes) / |credits|_1
def gpa(c, n):
    return sum([c_ * n_ for c_, n_ in zip(c, n)]) * 1.0 / sum(c)

# print info for credits and notes
def print_info(c, n):
    print('Credits %d GPA %f %.2f' % (sum(c), gpa(c, n), gpa(c, n)))

# print semesters
for c, n in zip(credits, notes): print_info(c, n)

# print total
c = [c for credits_ in credits for c in credits_ ]
n = [n for notes_ in notes for n in notes_]

print_info(c, n)
