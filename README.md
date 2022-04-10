# Vulkan in C, not C++  
  
**I WELCOME VOLUNTEERS**  
  
  
**NOTES**  
Do to scrupulous individuals, I was forced to write the license into the bottom of each file.  

This is a template that can be used to get started in coding Vulkan with the C language with GCC ( MinGW on windows ).  
  
Since I am on windows, I used this version of GCC / MinGW : https://nuwen.net/mingw.html  
  
Keep in mind, you will need to update the vulkan version number to the correct one you have installed. ( You might have installed Vulkan in a different path then where I did. )  
  
Get the VulkanSDK from here : https://vulkan.lunarg.com/  
  
I included the CGLM math library as well as the GLFW3 version that I used for this test template project.  

Added a very simple logger as well. I am planning to write a better version.  
  
The run.bat file is for windows users who want to simply click and go, as long as the same VulkanSDK version is installed, and is in the same path. I didn't use make, because I saw no point for this simple test.  
  
Slowly I am adding more to this template project over time. Example, I am thinking of adding Assimp.  
