# ECE4400_GroceryManager
## Overview
The Grocery manger is developed as a project for ECE 4400 Data Structures, this system utilizes advanced data structures to facilitate the addition, deletion, and organization of grocery items, alongside tracking customer purchase history.

## Features
- **Add Items**: Add new grocery items to the inventory with details like name, category, expiry date, and price.
- **Remove Items**: Remove items from the inventory or decrement their stock when needed.
- **Display Items**: Items can be displayed by various criteria such as price, expiry date, and category.
- **Customer History Tracking**: Track the history of customer purchases in a circular queue to understand customer preferences and purchase patterns.
- **Write to File**: Generate a JSON file of the grocery inventory, making it easy to share or analyze the inventory data.

## Data Structures Used
The system employs several key data structures to manage grocery inventory and operations efficiently:

- **Binary Search Tree (BST)**: Used to organize items by price and expiry date, allowing for efficient searching, insertion, and deletion based on these criteria.
- **Doubly Linked List (DLL)**: Facilitates the management of grocery items with operations such as addition, removal, and traversal of items in the inventory.
- **Circular Queue (CQ)**: Implements a fixed-size queue to track customer purchase history, showcasing the most recent purchases while maintaining a limited history size.
