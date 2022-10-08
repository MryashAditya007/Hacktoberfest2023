from tkinter import *  # import all the widgets
import os  #importing the os and shutil module
import shutil
from tkinter import messagebox as mb #import the mesassage box for displaying the messages
from tkinter import filedialog as fd  # imports the filedialog  box

# defining the function to open a file
def openAFile():
    # selecting a file using askopenfilename of filedialog as fd
    files = fd.askopenfilename(
        title="Select a file of any type",filetypes=[("All files", "*.*")]
    )
    os.startfile(os.path.abspath(files))


# function to copy a file
def copyAFile():
    # using the filedialog's askopenfilename() method to select the file
    copythefile = fd.askopenfilename(
        title="Select a file to copy",filetypes=[("All files", "*.*")]
    )
    # use the filedialog's askdirectory() method for selecting the directory
    dirToPaste = fd.askdirectory(title="Select the folder to paste the file")
    try:
        shutil.copy(copythefile, dirToPaste)
        mb.showinfo(title="File copied!",message="The file has been copied to the destination."
        )
    except:
        mb.showerror(title="Error!",message="File is unable to copy . Please try again!"
        )

# function to delete a file
def deleteAFile():
    # selecting the file using the filedialog's askopenfilename() method
    files = fd.askopenfilename(
        title="Choose a file to delete",filetypes=[("All files", "*.*")]
    )
    # delete the file using the remove() method
    os.remove(os.path.abspath(files))
    mb.showinfo(title="File deleted!", message="The selected file has been deleted.")


# function to rename a file
def renameAFile():
    rename_win = Toplevel(win_root)
    rename_win.title("Rename File")
    rename_win.geometry("300x100+300+250")
    rename_win.resizable(0, 0)
    rename_win.configure(bg="#F6EAD7")

    # create a lebel
    rename_label = Label(
        rename_win,text="Enter the file name:",font=("Calibri", "8"),bg="white",fg="blue"
    )
    # placing the label on the window
    rename_label.pack(pady=4)
    rename_field = Entry(rename_win,width=26,textvariable=fileNameEntered,relief=GROOVE,
        font=("Calibri", "10"),bg="white",fg="blue"
    )
    # placing the entry field on the window
    rename_field.pack(pady=4, padx=4)

    # creating a button
    submitButton = Button(
        rename_win,text="Submit",command=NameSubmit,width=14,relief=GROOVE,font=("Calibri", "9"),
        bg="white",fg="blue",activebackground="#709218",activeforeground="#FFFFFF"
    )
    submitButton.pack(pady=2)


# defining a function get the file path
def showFilePath():
    files = fd.askopenfilename(title="Select the file to rename", filetypes=[("All files", "*.*")])
    return files


# defining a function that will be called when submit button is clicked
def NameSubmit():
    renameName = fileNameEntered.get()
    # setting the entry field to empty string
    fileNameEntered.set("")
    fileName = showFilePath()
    # creating a new file name for the file
    newFileName = os.path.join(os.path.dirname(fileName), renameName + os.path.splitext(fileName)[1])
    os.rename(fileName, newFileName)
    mb.showinfo(title="File Renamed!", message="The selected file has been renamed.")


# defining a function to open a folder
def openAFolder():
    # using the filedialog's askdirectory() method to select the folder
    folder1 = fd.askdirectory(title="Select Folder to open")
    os.startfile(folder1)


# defining a function to delete the folder
def deleteAFolder():
    folderToDelete = fd.askdirectory(title='Select Folder to delete')
    os.rmdir(folderToDelete)
    mb.showinfo("Folder Deleted!", "The selected folder has been deleted!")


# defining a function to move the folder
def moveAFolder():
    folderToMove = fd.askdirectory(title='Select the folder you want to move')
    mb.showinfo(message='Folder has been selected to move. Now, select the desired destination.')
    des = fd.askdirectory(title='Destination')
    try:
        # using the move() method of the shutil module to move the folder to the requested location
        shutil.move(folderToMove, des)
        mb.showinfo("Folder moved!", 'The selected folder has been moved to the desired Location')
    except:
        mb.showerror('Error!', 'The Folder cannot be moved. Make sure that the destination exists')


#list all files in a folder
def listFilesInFolder():
    i = 0
    # using the askdirectory() method to select the folder
    folder1= fd.askdirectory(title="Select the Folder")
    files = os.listdir(os.path.abspath(folder1))
    listFilesWindow = Toplevel(win_root)
    # specifying the title of the pop-up window
    listFilesWindow.title(f'Files in {folder1}')
    listFilesWindow.geometry("300x500+300+200")
    listFilesWindow.resizable(0, 0)
    listFilesWindow.configure(bg="white")

    # creating a list box
    the_listbox = Listbox(
        listFilesWindow,selectbackground="#F24FBF",font=("Calibri", "10"),background="white"
    )
    the_listbox.place(relx=0, rely=0, relheight=1, relwidth=1)

    # creating a scroll bar
    the_scrollbar = Scrollbar(
        the_listbox,orient=VERTICAL,command=the_listbox.yview
    )
    the_scrollbar.pack(side=RIGHT, fill=Y)
    # setting the yscrollcommand parameter of the listbox's config() method
    the_listbox.config(yscrollcommand=the_scrollbar.set)

    # iterating through the files in the folder
    while i < len(files):
        # using the insert() method to insert the file details in the list box
        the_listbox.insert(END, "[" + str(i + 1) + "] " + files[i])
        i += 1
    the_listbox.insert(END, "")
    the_listbox.insert(END, "Total Files: " + str(len(files)))


if __name__ == "__main__":
    # creating an object of the Tk() class
    win_root = Tk()
    win_root.title("File Explorer")
    win_root.geometry("400x600+650+250")
    win_root.resizable(0, 0)
    win_root.configure(bg="white")

    # creating the frames using the Frame()
    header_frame = Frame(win_root, bg="#D8E9E6")
    buttons_frame = Frame(win_root, bg="skyblue")

    # using the pack() method to place the frames in the window
    header_frame.pack(fill="both")
    buttons_frame.pack(expand=TRUE, fill="both")

    # creating a label using the Label() widget
    header_label = Label(
        header_frame,text="File Explorer",font=("Calibri", "16"),bg="white",fg="blue"
    )

    # using the pack() method to place the label in the window
    header_label.pack(expand=TRUE, fill="both", pady=12)

    # creating open button
    open_button = Button(
        buttons_frame,text="Open a File",font=("Calibri", "15"),width=20,bg="white",fg="blue",relief=GROOVE,
        activebackground="blue",command=openAFile
    )
    # rename button
    rename_button = Button(
        buttons_frame,
        text="Rename a File",font=("Calibri", "15"),width=20,bg="white",fg="blue",relief=GROOVE,
        activebackground="white",command=renameAFile
    )

    # copy button
    copy_button = Button(
        buttons_frame,text="Copy the File",font=("Calibri", "15"),width=20,bg="white",fg="blue",
        relief=GROOVE,activebackground="blue",command=copyAFile
    )

    # delete button
    delete_button = Button(
        buttons_frame,text="Delete a File",font=("Calibri", "15"),width=20,bg="white",fg="blue",
        relief=GROOVE,activebackground="white",command=deleteAFile
    )
   # open folder button
    open_folder_button = Button(
        buttons_frame,text="Open a Folder",font=("Calibri", "15"),width=20,bg="white",fg="Blue",
        relief=GROOVE,activebackground="blue",command=openAFolder
    )

    # delete folder button
    delete_folder_button = Button(
        buttons_frame,text="Delete Folder",font=("Calibri", "15"),width=20,bg="white",fg="blue",relief=GROOVE,
        activebackground="blue",command=deleteAFolder
    )

    # move folder button
    move_folder_button = Button(
        buttons_frame,text="Move the Folder",font=("Calibri", "15"),width=20,bg="white",fg="Blue",relief=GROOVE,
        activebackground="Blue",command=moveAFolder
    )
    # list all files button
    list_button = Button(
        buttons_frame,text="List files in Folder",font=("Calibri", "15"),width=20,bg="white",fg="Blue",relief=GROOVE,
        activebackground="Blue",command=listFilesInFolder
    )
    # create an object of Stringvar class
    fileNameEntered = StringVar()

    # use the pack method to place the buttons
    open_button.pack(pady=9)
    rename_button.pack(pady=9)
    copy_button.pack(pady=9)
    delete_button.pack(pady=9)
    move_folder_button.pack(pady=9)
    open_folder_button.pack(pady=9)
    delete_folder_button.pack(pady=9)
    list_button.pack(pady=10)
    win_root.mainloop()