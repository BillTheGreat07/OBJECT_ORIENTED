public class Main {
    public static void main(String[] args) { // Create an instance of RentalService
        
        RentalService rentalService = new RentalService();

        // Add vehicles to the rental service
        rentalService.addVehicle(new Car("GR1234", "Nissan Versa", 50.0, true));
        rentalService.addVehicle(new Motorcycle("GR5678", "Ducati Monster", 75.0, 600));

        // Demonstrate getting details and calculating rental cost
        Vehicle car = rentalService.findVehicleByLicensePlate("GR1234");
        if (car != null) {
            System.out.println(car.getDetails());
            System.out.println("Rental cost for 5 days: $" + car.calculateRentalCost(5));
        }

        Vehicle motorcycle = rentalService.findVehicleByLicensePlate("GR5678");
        if (motorcycle != null) {
            System.out.println(motorcycle.getDetails());
            System.out.println("Rental cost for 3 days: $" + motorcycle.calculateRentalCost(3));
        }

        // Calculate and display the total income from rentals
        System.out.println("Total income for 5 days rental: $" + rentalService.calculateTotalIncome(5));
    }
}
