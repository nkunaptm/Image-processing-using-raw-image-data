# Image-processing-using-raw-image-data
The Interface.cpp file is the file with the main function and is the one that handles input from the user.
The VilImage.cpp implememnts the functions from Volimage.h, it can fill the slices vector with raw images then extract an image or find the difference between 2 images
the header file should be ".dat"
To find the difference of images use command : ./volimage <imageBase> -d i j output_file_name
if the images are in a folder please specify the folder name together with the base name. an example command is : ./volimage brain_mri_raws/MRI -d 39 118 diff.raw
where "brain_mri_raws" is the folder MRI is in.
The command for extracting a file is : ./volimage <imageBase> -x i output_file_name
if the images are in a folder please specify the folder name together with the base name. an example command is : ./volimage brain_mri_raws/MRI -x 0 new.raw
the output file will be in the directory your .cpp files are in
for the no optional flags command is : ./volimage <imageBase>
for example : ./volimage brain_mri_raws/MRI
