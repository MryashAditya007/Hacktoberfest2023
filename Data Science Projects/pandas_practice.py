#!/usr/bin/env python
# coding: utf-8

# In[70]:



import pandas as pd
import numpy as np


# In[71]:


data = pd.read_csv("/content/sample_data/california_housing_test.csv")
titanic = pd.read_csv("/content/train_titanic.csv")
data


# In[72]:


#firt five element of data
data.head()


# In[73]:


#last five elements of data
data.tail()


# In[ ]:



#get the list of colums
print(data.columns)
#get the list of index
print(data.index)


# In[ ]:


#rename columns
data.rename(columns = {"latitude":"lat", "longitude":b"long"})


# In[ ]:


#only want columns total_rooms, population and median income

data[['total_rooms', 'population', 'median_income']] 


# In[ ]:


#Find total rooms of 167th house
print(data.loc[167])
data.loc[167]['total_rooms']


# In[ ]:


#calculate the mean population
print(np.mean(data['population']))
print(data['population'].mean())


# In[ ]:


#check if the data has any NULL value
data.isnull().sum()


# In[ ]:


#checking for NAN values
titanic.isna().sum()


# In[ ]:



titanic.isna()


# In[ ]:


#create a new column which contains ratio of total rooms and total bedrooms
data["ratio_of_rooms_vs_bedrroms"] = data["total_rooms"]/data["total_bedrooms"]
data.head()


# In[ ]:


titanic


# In[ ]:


#check number of males and females
titanic["Sex"].value_counts()


# In[ ]:


#median age of people boarded titanic
titanic['Age'].median()


# In[ ]:


#how many of people survived?
print(titanic["Survived"].sum())
print(titanic["Survived"].value_counts())


# In[ ]:


titanic.drop(['Name', 'Ticket'], axis = 1)


# In[ ]:


#Access Cabin of 659th person
titanic.loc[659]['Cabin']


# In[ ]:


data.corr()


# In[ ]:





# In[ ]:


#filter data
# titanic[titanic["Sex"]=="female"]
titanic[(titanic["Sex"]=="female") & (titanic["Survived"]==1)]


# In[ ]:


data[data["housing_median_age"]<=10]


# In[ ]:


data[(data["median_house_value"]<100000) & (data["total_bedrooms"] < 100)]


# In[ ]:


#dqta of all the survived males
titanic[(titanic["Pclass"]==2) & (titanic["Survived"]==1)]


# In[79]:


titanic.where((titanic["Sex"] == "female") & (titanic["Survived"] == 1))


# In[82]:


titanic.groupby('Pclass')['Survived'].sum()


# In[83]:


titanic.groupby('Pclass')['Sex'].value_counts()


# In[102]:



# titanic[(titanic["Pclass"]==2) & (titanic["Sex"]=="female")].count()


# In[87]:


titanic.groupby('Pclass')['Fare'].mean()


# In[94]:



titanic.groupby(['Pclass', 'Sex'])['Fare'].mean()

