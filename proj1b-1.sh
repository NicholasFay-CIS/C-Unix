mkdir $1  #makes the root directory
cd $1     #change to root directory
mkdir Dir1 #In root, make dir1
mkdir Dir2 #In root, make dir2
cd Dir1 # change directory  to Dir1
mkdir Dir3 #makes directory 3
cd Dir3 #change to directory 3
mkdir Dir4 #make directory 4
cd Dir4 #change to directory 4
touch File4 #create file4
touch File3 #create file3
chmod 666 File4 #sets permissions for file4
chmod 200 File3 #perm for file3
cd .. #change directory to dir 3
chmod 750 Dir4 #sets perm for Dir4
cd .. #change to directory 1
touch File1 #creates File1
chmod 400 File1
chmod 000 Dir3 #sets directory 3 perm
cd .. #change to root directory
chmod 770 Dir1 #giver permission to Dir1
cd Dir2 #change to Dir2
touch File2 #create File2
chmod 640 File2 #set file permissions
cd .. #back to root dir
chmod 775 Dir2 #changes permissions for Dir2
