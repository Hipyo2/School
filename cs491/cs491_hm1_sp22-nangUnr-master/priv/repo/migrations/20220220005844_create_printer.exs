defmodule Cs491Hm1.Repo.Migrations.CreatePrinter do
  use Ecto.Migration

  def change do
    create table(:printer) do
      add :model, :string
      add :inventory_code, :integer
      add :office_number, :integer
      add :building, :string

      timestamps()
    end
  end
end
