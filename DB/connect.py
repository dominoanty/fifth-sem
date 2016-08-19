import MySQLdb
#Connect to LocalDB
db = MySQLdb.connect("localhost","root","root","testdb")
cursor = db.cursor()

def display():
   #Get row details
    cursor.execute("select * from user_table")
    data = cursor.fetchone()
    while data != None:
        for x,y in enumerate(data):
            print "%s : %s" % (rowinfo[x], y)
        data = cursor.fetchone()

def create():
    for field in rowinfo:
        print "Enter %s : " % (field)
        temp.append(raw_input())
    sql = "INSERT INTO user_table VALUES\
           (%s, '%s', '%s') " % (temp[0], temp[1], temp[2])
    try:
        cursor.execute(sql)
        db.commit()
    except Exception as e:
        print e
        print "Error occurred"
        db.rollback()
def delete(id):
    sql = "DELETE from user_table where id = %s" %(id)

    try:
        cursor.execute(sql)
        db.commit()
    except Exception as e:
        print e
        print "Error ocurred"
        db.rollback()
    finally:
        print "Operation completed successfully"

if __name__ == "__main__":
     #Get table details
    cursor.execute("describe user_table")
    temprow = cursor.fetchone()
    rowinfo = []
    while temprow != None:
        rowinfo.append( temprow[0])
        temprow = cursor.fetchone()
    print rowinfo

    opt = 0
    temp = []
    tempid = 0
    while opt != 10:
        print "1. Create a row "
        print "2. Read (Display"
        print "3. Update a row"
        print "4. Delete a row"
        opt = int(raw_input())
        if opt == 1:
            create()
        elif opt == 2:
            display()
        elif opt == 4:
            print "Enter id to delete row : "
            tempid = int(raw_input())
            delete(tempid)
        elif opt == 3:
            print "Under construction"
        else:
            opt =10
            

        
db.close()
