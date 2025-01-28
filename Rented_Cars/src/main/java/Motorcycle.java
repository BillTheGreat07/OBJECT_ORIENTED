public class Motorcycle extends Vehicle {
  private final int engineCC;

  public Motorcycle(String licensePlate, String model, double dailyRate, int engineCC) {
      super(licensePlate, model, dailyRate);
      this.engineCC = engineCC;
  }

  @Override
  public double calculateRentalCost(int days) {
      double baseCost = days * dailyRate;
      return engineCC > 500 ? baseCost * 1.2 : baseCost;
  }
}
