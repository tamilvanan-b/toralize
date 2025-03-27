## Checking if Tor is Installed

Before installing Tor, let's check if it's already installed and running on your system:

1. Open a terminal and run the following command to check if Tor is installed:

   ```
   tor --version
   ```

   - If Tor is installed, this will display the version of Tor.
   - If Tor is **not installed**, the command will return an error indicating that Tor is not found.

2. To check if the Tor service is running, use:

   ```
   systemctl status tor
   ```

   - If Tor is running, this will show the status of the Tor service.
   - If Tor is **not installed** or not running, you will see a message indicating that the service is not found.

---

## Installing Tor (If Not Installed)

If Tor is not installed, follow the steps below to install and start the Tor service.

### Step 1: Update the System

First, update your package list to ensure you are getting the latest versions:

```
sudo apt update
```

### Step 2: Install Tor

Install the Tor package by running:

```
sudo apt install tor
```

### Step 3: Start and Enable the Tor Service

Once installed, you can start the Tor service and enable it to start automatically on boot:

1. **Start the Tor service:**

   ```
   sudo systemctl start tor
   ```

2. **Enable Tor to start on boot:**

   ```
   sudo systemctl enable tor
   ```

   This ensures that Tor will automatically start whenever the system reboots.

---

## Verifying the Installation

After completing the installation and starting the service, you can verify that the Tor service is running properly:

1. Check the service status:

   ```bash
   systemctl status tor
   ```

2. If everything is working correctly, you should see output indicating that Tor is active and running.

---