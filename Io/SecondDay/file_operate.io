//  matrix.io
matrix := list(
   list(1, 2, 3),
   list(4, 5, 6),
   list(7, 8, 9)
)

file_path := "test_matrix.txt"
data := File open(file_path)
#Transform the matrix into a sequence and write it into the file
#data File write(matrix serialized)
data write(matrix serialized)
data close

#Read solution 1: use File open(still a serialized file)
readData := File open(file_path)
readData readLine println
readData close

"\ndoFile:" println
#Read solution 2: use doFile
readData2 := doFile(file_path)
readData2 println
#readData2 close
